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

int search_time = 0;
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
bool is_search;
int output_search[20][7];

int main() {
	init(Temp_student);
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
			//is_search = false; //默认不是搜索状态，采用常规的列表显示
			if (selected_combo_main == "add student profile")
			{
				is_search = false;
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
			else if (selected_combo_main == "change student profile") //修改学生信息界面
			{
				is_search = false;
				express_log = "press finish to save changes";
			}
			else if (selected_combo_main == "search student profile") { //查询学生信息系统，采用的是可以多条件叠加，并且实时显示
				is_search = true; //进入搜索状态
				search(Namelist, TextBox, selected_combo, search_time); //获取output数组
				express_log = selected_combo + " filtered...";
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
				if (selected_combo == "Name") //输入名字时
				{
					Namelist[selected - 1].Name = TextBox;  //直接保存到项目文件里面
					express_log = "Name changed..";
				}
				else if (selected_combo == "Sex")
				{
					Namelist[selected - 1].Sex = TextBox;
					express_log = "Sex changed..";
				}
				else if (selected_combo == "Age")
				{
					Namelist[selected - 1].Age = TextBox;
					express_log = "Age changed..";
				}
				else if (selected_combo == "PhoneNumber")
				{
					Namelist[selected - 1].PhoneNumber = TextBox;
					express_log = "PhoneNumber changed..";
				}
				else if (selected_combo == "Major")
				{
					Namelist[selected - 1].Major = TextBox;
					express_log = "Major changed..";
				}
				else if (selected_combo == "Academy")
				{
					Namelist[selected - 1].Academy = TextBox;
					express_log = "Academy changed..";
				}
				else if (selected_combo == "Univercity")
				{
					Namelist[selected - 1].univercity = TextBox;
					express_log = "Univercity changed..";
				}
			}
			//--------------------------------------------查询学生信息-----------------------------//、
			else if (selected_combo_main == "search student profile" && search_time < 7) {
				search_time += 1; //进入下一个
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
		ImGui::SameLine();
		if (is_search)
		{
			if (ImGui::Button("ClearFilter")) {
				search_time = 0;
				for (int i = 0; i < 20; i++)
				{
					for (int j = 1; j < 7;j++) {
						output_search[i][j] = 0; //重置查询数据
					}
				}
			}
		}

		ImGui::Text(express_log.c_str());

		if (ImGui::BeginListBox("outputs"))
		{
			if (list_flag && !is_search)  //没有在搜索状态

				for (int j = 0; j < 20; j++)
				{
					output = "key:" + to_string(Namelist[j].key) + "  Name:" + Namelist[j].Name + " Sex:" + Namelist[j].Sex + " Age:" + Namelist[j].Age;
					if (ImGui::Selectable(output.c_str()))
					{
						//cout << Namelist[j].key << endl;
						selected = Namelist[j].key;//存储点击对象的key值
					}
				}

			else if (is_search && list_flag) //搜索模式的显示
			{
				for (int i = 0; i < 20; i++) //最多七次的叠加排序，必须要同时满足才行
				{
					for (int j = 1; j < 7;j++) {
						output_search[i][0] += output_search[i][j]; //把总和存储在第一项里面
					}
				}
				for (int i = 0; i < 20; i++)
				{
					if (output_search[i][0] == search_time && search_time != 0) { //筛选成功
						output = "key:" + to_string(Namelist[i].key) + "  Name:" + Namelist[i].Name + " Sex:" + Namelist[i].Sex + " Age:" + Namelist[i].Age;
						ImGui::Text(output.c_str());
					} //输出筛选的项目
				}
			}
			ImGui::EndListBox();
		}
		ImGui::Text("key selected :");
		ImGui::SameLine();
		ImGui::Text(to_string(selected).c_str());
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