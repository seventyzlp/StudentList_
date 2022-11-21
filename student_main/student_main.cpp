#define GLEW_STATIC //静态链接库
//------------------------------------------------ 图形窗口初始化--------------------------------//
#include <GL/glew.h>
#include <glfw3.h>
#include "student_define.h"
#include <iostream>

#pragma comment(lib,"../API/GLEW/glew32s.lib")
#pragma comment(lib,"../API/GLFW/glfw3.lib")
#pragma comment(lib,"Opengl32.lib") //导入openGL
#pragma once
//------------------------------------------------ 图形界面绘制--------------------------------//
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

using namespace std;
GLFWwindow* Windows;
//---------------------------------------------------------------------------------------------//
#include "student_define.h"

char TextBox[20];
string test_text = "hello world";
int Your_faith;
Student Namelist[20]; //初始化学生名单
Student Temp_student;

string selected_combo_main = "select"; //选项
string selected_combo = "select"; //小选项
string express_log = "waiting for express logs...";
string output;
int i;
int selected;
bool list_flag;
int main() {
	Temp_student.Name = "empty"; //初始化临时变量
	Temp_student.Sex = "empty";
	Temp_student.Age = "empty";
	Temp_student.PhoneNumber = "empty";
	Temp_student.Major = "empty";
	Temp_student.Academy = "empty";
	Temp_student.univercity = "empty";
	//----------------------------------------窗口初始化------------------------------------------//
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Windows = glfwCreateWindow(800, 600, "Windows", NULL, NULL); //设置窗口属性

	glfwMakeContextCurrent(Windows);
	glfwSwapInterval(0);
	//------------------------------------IMGUI初始化-----------------------------------------------//
	ImGui::CreateContext(NULL);
	ImGui::StyleColorsDark();
	ImGuiIO& io = ImGui::GetIO();(void)io; //输入输出
	ImGui_ImplGlfw_InitForOpenGL(Windows, true);//初始化
	ImGui_ImplOpenGL3_Init("#version 330");
	//-------------------------------------------------------------------------------------------------//
	while (!glfwWindowShouldClose(Windows)) {
		//--------------------帧初始化--------------------//
		glClear(GL_COLOR_BUFFER_BIT);//清除残影
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		//-------------------------------------------//
		ImGui::Begin("StudentsList_zlp_edited");//窗口开始

		if (ImGui::BeginCombo("choice you want", selected_combo_main.c_str()))
		{
			if (ImGui::Selectable("search student profile")) // 查询学生信息
			{
				selected_combo_main = "search student profile";
			}

			if (ImGui::Selectable("add student profile")) // 添加学生信息
			{
				selected_combo_main = "add student profile";
			}

			if (ImGui::Selectable("change student profile")) // 修改学生信息
			{
				selected_combo_main = "change student profile";
			}

			ImGui::EndCombo();
		}

		if (ImGui::BeginCombo("choice the detail section", selected_combo.c_str()))
		{
			if (ImGui::Selectable("Name")) //设置选项
			{
				selected_combo = "Name";
			}

			if (ImGui::Selectable("Sex"))
			{
				selected_combo = "Sex";
			}

			if (ImGui::Selectable("Age"))
			{
				selected_combo = "Age";
			}

			if (ImGui::Selectable("PhoneNumber"))
			{
				selected_combo = "PhoneNumber";
			}

			if (ImGui::Selectable("Major"))
			{
				selected_combo = "Major";
			}

			if (ImGui::Selectable("Academy"))
			{
				selected_combo = "Academy";
			}

			if (ImGui::Selectable("univercity"))
			{
				selected_combo = "univercity";
			}

			ImGui::EndCombo();
		}

		ImGui::InputText("input your texts", TextBox, 20); //想要自适应长度就用 IM_ARRAYSIZE  输入框

		if (ImGui::Button("Accept")) //确认输入信息 按下accept按钮
		{
			if (selected_combo_main == "add student profile")
			{
				if (selected_combo == "Name") //输入名字时
				{
					Temp_student.Name = TextBox;
					express_log = "Name set..";
					Temp_student.is_changed = true; //点下accept按钮时，无论输入了什么都是已经编辑的状态
				}
				else if (selected_combo == "Sex")
				{
					Temp_student.Sex = TextBox;
					express_log = "Sex set..";
					Temp_student.is_changed = true;
				}
				else if (selected_combo == "Age")
				{
					Temp_student.Age = TextBox;
					express_log = "Age set..";
					Temp_student.is_changed = true;
				}
				else if (selected_combo == "PhoneNumber")
				{
					Temp_student.PhoneNumber = TextBox;
					express_log = "PhoneNumber set..";
					Temp_student.is_changed = true;
				}
				else if (selected_combo == "Major")
				{
					Temp_student.Major = TextBox;
					express_log = "Major set..";
					Temp_student.is_changed = true;
				}
				else if (selected_combo == "Academy")
				{
					Temp_student.Academy = TextBox;
					express_log = "Academy set..";
					Temp_student.is_changed = true;
				}
				else if (selected_combo == "Univercity")
				{
					Temp_student.univercity = TextBox;
					express_log = "Univercity set..";
					Temp_student.is_changed = true;
				}
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Finish")) //把结束全体的输入
		{
			for (i = 0; i < 20; i++)
			{
				//cout << i << endl;
				if (!Namelist[i].is_used) {
					Temp_student.key = i + 1; //并且赋值给temp 第一个数据就是1
					//cout << "录入数据key：" << i << endl;
					break; //找到数组最后位置
				}
			}
			//-------------------------------------------添加学生成员-----------------------------------------//
			if (selected_combo_main == "add student profile" && Temp_student.key < 21)
			{
				if (Temp_student.is_changed == false) { //如果没有修改过，那么点finish就没有用
					express_log = "remain unchanged!";
					cout << "unchanged" << endl;
				}
				else //修改过 ，那么就写入到对象数组中
				{
					Namelist[i] = Temp_student;
					Namelist[i].is_used = true; //设置结构体数组被占用，也就是说进入下一排的数据编写
					init(Temp_student);
					//cout << Namelist[i].key << endl;//看一眼key有没有被放进去 放进去了

					express_log = "operation finished...";
				}
			}
			else if (Temp_student.key >= 21 && selected_combo_main == "add student profile")//人满了
			{
				express_log = "the list is Full!";
			}
			//--------------------------------------------修改学生信息-------------------------------------//
			if (selected_combo_main == "change student profile")
			{
				init(Temp_student);
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("List")) {
			list_flag = true; //修改可以看到list
		}
		ImGui::SameLine();
		if (ImGui::Button("NOList")) {
			list_flag = false;//修改不可以看到list
		}
		ImGui::Text(express_log.c_str());

		if (ImGui::BeginListBox("outputs"))
		{
			if (list_flag)  //flag 为true允许展示
			{				//排除是output变量重复导致问题，排除循环导致，他妈的怎么回事
				for (int j = 0; j < 20; j++)
				{
					output = "key:" + to_string(Namelist[j].key) + "  Name:" + Namelist[j].Name + " Sex:" + Namelist[j].Sex + " Age:" + Namelist[j].Age;
					if (ImGui::Selectable(output.c_str()))
					{
						cout << Namelist[j].key << endl;
					}
				}
			}
			ImGui::EndListBox();
		}

		// ImGui::ShowDemoWindow(); //实例项目
		//-------------------------------------绘制窗口--------------------------//
		ImGui::End();//窗口结束
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); //获取要画的内容

		glfwSwapBuffers(Windows); //生成窗口
		glfwPollEvents();//固定窗口
	}
	return 0;
}