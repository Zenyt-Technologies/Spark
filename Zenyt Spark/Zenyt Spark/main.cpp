#include "Zenyt Spark.h"
#include "GLFW/glfw3.h"
#include <imgui.h>

using namespace std;

int main()
{
	printf("Boot Zenyt Spark\n");

    GLFWwindow* window;

    if (!glfwInit()) {
        printf("Zenyt Spark failed to initialize GLFW.\n");
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_MAXIMIZED, true);

    window = glfwCreateWindow(1280, 720, "Zenyt Spark", NULL, NULL);
    if (!window)
    {
        printf("Zenyt Spark failed to allocate a window.\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);


        ImGui::Begin("Zenyt Spark");

        ImGuiIO& io = ImGui::GetIO();
        ImGuiStyle& style = ImGui::GetStyle();

        // Create a docking space
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);

        // Create a dockable window
        if (ImGui::Begin("My Dockable Window"))
        {
            ImGui::Text("This is a dockable window!");
            ImGui::End();
        }

        ImGui::End();


        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
