//bpp.cpp: The source code for Blender++.
#define GLFW_DLL

#include "include/glad.h"
#include <GLFW/glfw3.h>

#include <boost/program_options.hpp>

#include <ncursesw/curses.h>

#include <iostream>
#include <iterator>
#include <string_view>
#include <string>
#include <cstring>

#ifdef _WIN32
#include <windows.h>
#endif

namespace bpp {
  namespace variables {
    short int active_renderer;
  }

  namespace text_colors {
    std::string reset = "\x1b[0m";
    namespace foreground {
      std::string alice_blue = "\x1b[38;2;240;248;255m";
      std::string pale_amaranth_pink = "\x1b[38;2;221;190;195m";
      std::string amaranth_pink = "\x1b[38;2;241;156;187m";
      std::string bright_amaranth_pink = "\x1b[38;2;255;53;94m";
      std::string amaranth = "\x1b[38;2;229;43;80m";
      std::string amaranth_magenta = "\x1b[38;2;237;60;202m";
      std::string amaranth_cerise = "\x1b[38;2;205;38;130m";
      std::string amaranth_purple = "\x1b[38;2;171;39;79m";
      std::string amaranth_deep_purple = "\x1b[38;2;159;43;104m";
    }

    namespace background {
      //Put stuff here later
    }
  }

  namespace tests {
    void clr(void);
  }

  namespace functions {
    void check_params(int pargc, char **pargv);
    void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    void process_input(GLFWwindow *window);
  }

  namespace windows {
    GLFWwindow *start_window;
  }

  void start(short int renderer);
  void quit(short int retval);
}

int main(int argc, char *argv[]) {
  #ifdef _WIN32
  HANDLE win_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  HANDLE win_hConsole_custom = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
  SetConsoleActiveScreenBuffer(win_hConsole_custom);
  DWORD win_consoleMode = 0;
  GetConsoleMode(win_hConsole_custom, &win_consoleMode);
  win_consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(win_hConsole_custom, win_consoleMode);
  #endif //See https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797 or ANSI.md

  bpp::functions::check_params(argc, argv);
  std::cout << "Next time you run Blender++, make sure to pass an argument this time like --renderer-gl." << std::endl;
  bpp::quit(0);
}

void bpp::start(short int renderer) {
  switch (renderer) {
    case 0:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] \x1b[38;2;255;174;201mCPU renderer is still under construction. Sorry!" << std::endl;
      bpp::quit(0);
      break;
    
    case 1:
      glfwInit(); //GLFW: Initialize and configure
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
      #ifdef __APPLE__
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
      #endif

      bpp::windows::start_window = glfwCreateWindow(800, 600, "Blender++", NULL, NULL); //GLFW window creation
      if (bpp::windows::start_window == NULL) {
        glfwTerminate();
        bpp::quit(1);
      }
    
      glfwMakeContextCurrent(bpp::windows::start_window);
      glfwSetFramebufferSizeCallback(bpp::windows::start_window, bpp::functions::framebuffer_size_callback);

      if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { //GLAD: Load all OpenGL function pointers
        bpp::quit(2);
      }

      //Print information about detected hardware
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Using OpenGL version " << std::string((char*)glGetString(GL_VERSION)) << std::endl;
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Detected GPU vendor " << std::string((char*)glGetString(GL_VENDOR)) << std::endl;
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Rendering on GPU " << std::string((char*)glGetString(GL_RENDERER)) << std::endl;
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Found GLSL version " << std::string((char*)glGetString(GL_SHADING_LANGUAGE_VERSION)) << std::endl;


      //Render loop
      while (!glfwWindowShouldClose(bpp::windows::start_window)) {
        bpp::functions::process_input(bpp::windows::start_window); //Process input

        //Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(bpp::windows::start_window); //Swap buffers
        glfwPollEvents(); //Poll I/O events (keys pressed/released, mouse moved etc.)
      }

      //Terminate.
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Terminating GLFW." << std::endl;
      glfwTerminate();
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] GLFW has been gracefully terminated. Exiting..." << std::endl;
      bpp::quit(0);
      break;
    
    case 2:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Vulkan renderer still under construction! Sorry :(" << std::endl;
      break;

    case 3:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Metal renderer still under construction! Sorry :(" << std::endl;
      break;
    
    case 4:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Direct3D 9 renderer still under construction! Sorry :(" << std::endl;
      break;

    case 5:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Direct3D 10 renderer still under construction! Sorry :(" << std::endl;
      break;

    case 6:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Direct3D 11 renderer still under construction! Sorry :(" << std::endl;
      break;

    case 7:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Direct3D 12 renderer still under construction! Sorry :(" << std::endl;
      break;
    
    case 8:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] TUI renderer still under construction! Sorry :(" << std::endl;
  }
}

void bpp::tests::clr(void) {
  std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Beginning color tests." << std::endl << std::endl;

  std::cout << bpp::text_colors::foreground::alice_blue << "Alice blue" << std::endl;
  std::cout << bpp::text_colors::foreground::pale_amaranth_pink << "Pale amaranth pink" << std::endl;
  std::cout << bpp::text_colors::foreground::amaranth_pink << "Amaranth pink" << std::endl;
  std::cout << bpp::text_colors::foreground::bright_amaranth_pink << "Bright amaranth pink" << std::endl;
  std::cout << bpp::text_colors::foreground::amaranth << "Amaranth" << std::endl;
  std::cout << bpp::text_colors::foreground::amaranth_magenta << "Amaranth magenta" << std::endl;
  std::cout << bpp::text_colors::foreground::amaranth_cerise << "Amaranth cerise" << std::endl;
  std::cout << bpp::text_colors::foreground::amaranth_purple << "Amaranth purple" << std::endl;
  std::cout << bpp::text_colors::foreground::amaranth_deep_purple << "Amaranth deep purple" << std::endl;

  std::cout << bpp::text_colors::reset << std::endl;
  bpp::quit(0);
}

void bpp::quit(short int retval) {
  switch (retval) {
    case 0:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Blender++ terminated, returned error code 0 (nothing went wrong, successful exit). " << std::endl;
      break;
    case 1:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Blender++ terminated, returned error code 1 (failed to create GLFW window. Run Blender++ with --errorhelp-1 for possible fixes)." << std::endl;
      break;
    case 2:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Blender++ terminated, returned error code 2 (failed to initialize GLAD. Run Blender++ with --errorhelp-2 for possible fixes)." << std::endl;
      break;
    case 3:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Blender++ terminated, returned error code 3 (bad arguments. Run Blender++ with --errorhelp-3 for possible fixes). " << std::endl;
      break;
    default:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Blender++ terminated with unknown error." << std::endl;
      break;
  }

  exit(retval);
}

void bpp::functions::process_input(GLFWwindow *window) { //Query GLFW whether relevant keys are pressed/released this frame and react accordingly
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true); //Escape obviously means "Quit".
  }
}

void bpp::functions::framebuffer_size_callback(GLFWwindow *window, int width, int height) { //This gets called whenever the window gets resized
  glViewport(0, 0, width, height); //Make sure the viewport is the same size as the window.
}

void bpp::functions::check_params(int pargc, char **pargv) {
  short int errorcode;
  short int renderer;

  try {
    boost::program_options::options_description options_description("Blender++ v0.0.1.0 Help");
    options_description.add_options()
      ("help", "Print help message (the thing you're reading right now)")
      ("errorhelp", "Print basic information about all error codes")
      ("errorcode", boost::program_options::value(&errorcode) , "Displays a longer description for a specific error code with possible solutions. Replace 'arg' with your error code")
      ("renderer-cpu", "Use CPU renderer")
      ("renderer-gdi", "Use GDI renderer (Windows only)")
      ("renderer-gdiplus", "Use GDI+ renderer (Windows only)")
      ("renderer-gl", "Use OpenGL 4.6 renderer")
      ("renderer-vulkan", "Use Vulkan 1.3 renderer")
      ("renderer-metal", "Use Metal renderer (macOS only)")
      ("renderer-d3d9", "Use Direct3D 9 renderer (Windows only)")
      ("renderer-d3d10", "Use Direct3D 10 renderer (Windows only)")
      ("renderer-d3d11", "Use Direct3D 11 renderer (Windows only)")
      ("renderer-d3d12", "Use Direct3D 12 renderer (Windows only)")
      ("clr-test", "Test the color printing system to make sure that it works");

    boost::program_options::variables_map variables_map;
    boost::program_options::store(boost::program_options::parse_command_line(pargc, pargv, options_description), variables_map);
    boost::program_options::notify(variables_map);

    if (variables_map.count("renderer-cpu")) {
      bpp:start(0);
      bpp::quit(0);
    }

    if (variables_map.count("renderer-gdi")) {
      #ifdef _WIN32
      bpp::start(1);
      #else
      std::cout << "The GDI renderer is for Windows devices only, sorry." << std::endl;
      #endif
      bpp::quit(0);
    }

    if (variables_map.count("renderer-gdiplus")) {
      #ifdef _WIN32
      bpp::start(2);
      #else
      std::cout << "The GDI+ renderer is for Windows devices only, sorry." << std::endl;
      #endif
      bpp::quit(0);
    }

    if (variables_map.count("renderer-gl")) {
      bpp::start(3);
      bpp::quit(0);
    }

    if (variables_map.count("renderer-vulkan")) {
      bpp::start(4);
      bpp::quit(0);
    }

    if (variables_map.count("renderer-metal")) {
      #ifdef __APPLE__
      bpp::start(5);
      #else
      std::cout << "The Metal renderer is for Apple devices only, sorry." << std::endl;
      #endif
      bpp::quit(0);
    }

    if (variables_map.count("renderer-d3d9")) {
      #ifdef _WIN32
      bpp::start(6);
      #else
      std::cout << "The Direct3D 9 renderer is for Windows devices only, sorry." << std::endl;
      #endif
      bpp::quit(0);
    }

    if (variables_map.count("renderer-d3d10")) {
      #ifdef _WIN32
      bpp::start(7);
      #else
      std::cout << "The Direct3D 10 renderer is for Windows devices only, sorry." << std::endl;
      #endif
      bpp::quit(0);
    }

    if (variables_map.count("renderer-d3d11")) {
      #ifdef _WIN32
      bpp::start(8);
      #else
      std::cout << "The Direct3D 11 renderer is for Windows devices only, sorry." << std::endl;
      #endif
      bpp::quit(0);
    }

    if (variables_map.count("renderer-d3d12")) {
      #ifdef _WIN32
      bpp::start(9);
      #else
      std::cout << "The Direct3D 12 renderer is for Windows devices only, sorry." << std::endl;
      #endif
      bpp::quit(0);
    }

    if (variables_map.count("help")) {
      //Refer to 'newhelpmsg.txt' and 'orighelpmsg.txt'
      //Text converted with https://tomeko.net/online_tools/cpp_text_escape.php?lang=en
      std::cout << options_description << std::endl;
      //std::cout << "Blender++ v0.0.1.0 Help:" << std::endl << "  --help                Print help message (the thing you're reading right now)" << std::endl << "  --errorhelp           Print basic information about all error codes" << std::endl << "  --errorcode arg       Displays a longer description for a specific error code with possible solutions. Replace 'arg' with your error code" << std::endl << "" << std::endl << "  --renderer-cpu        Use CPU renderer" << std::endl << "  --renderer-tui        Use the TUI (Text User Interface via NCURSES) renderer (severely limited functionality)" << std::endl << "  --renderer-gl46       Use OpenGL 4.6 renderer" << std::endl << "  --renderer-vulkan     Use Vulkan 1.3 renderer" << std::endl << "  --renderer-metal      Use Metal renderer (macOS only)" << std::endl << "  --renderer-d3d9       Use Direct3D 9 renderer (Windows only)" << std::endl << "  --renderer-d3d10      Use Direct3D 10 renderer (Windows only)" << std::endl << "  --renderer-d3d11      Use Direct3D 11 renderer (Windows only)" << std::endl << "  --renderer-d3d12      Use Direct3D 12 renderer (Windows only)" << std::endl << "" << std::endl << "Please visit https://github.com/HackerDaGreat57/bpp for more information, source code, and additional help." << std::endl;
      bpp::quit(0);
    }

    if (variables_map.count("errorhelp")) {
      std::cout << "There are different types of errors in Blender++. And it is generally good computer programming practice to assign an ID or code to every error. The types of errors in Blender++ are listed below. Run the application with --errorhelp {your error code here} to learn about possible solutions for your error." << std::endl;
      std::cout << "0: Success. Nothing to worry about." << std::endl;
      std::cout << "1: Failed to create GLFW window." << std::endl;
      std::cout << "2: Failed to initialize GLAD." << std::endl;
      std::cout << "3: Couldn't recognise an argument." << std::endl;
      std::cout << std::endl << "If you get any other kind of error, please try reinstalling Blender++. If none of these options work, you can reach out to me at HackerDaGreat57@gmail.com." << std::endl << std::endl;
      bpp::quit(0);
    }

    if (variables_map.count("errorcode")) {
      switch (errorcode) {
        case 0:
          std::cout << "Error 0: Success. (BTW this is the reason why early versions of Windows used to say \"Task failed successfully.\" until someone realized that meant to opposite of what it was supposed to mean." << std::endl;
          bpp::quit(0);
        case 1:
          std::cout << "Error 1: Failed to create GLFW window. This means that your graphics card (aka GPU) doesn't support OpenGL 4.6. Try rerunning Blender++ with --renderer-cpu." << std::endl;
          bpp::quit(0);
        case 2:
          std::cout << "Error 2: Failed to initialize GLAD. This means that your computer either does not have a graphics card (aka GPU) or is too old. Try running the application with --renderer-cpu." << std::endl;
          bpp::quit(0);
        case 3:
          std::cout << "Error 3: Invalid arguments. This means that one of the application's command-line settings (the things that are seperated by spaces and begin with --) are incorrect and probably have a spelling error. Check your arguments carefully and make sure that not a single letter is off. Remember, the command-line doesn't have autocorrect!" << std::endl;
          bpp::quit(0);

        default:
          std::cout << "Invalid error code. Try again with the right number this time" << std::endl;
          bpp::quit(0);
      }
    }

    if (variables_map.count("clr-test")) {
      bpp::tests::clr();
      bpp::quit(0);
    }
  }

  catch(std::exception &exception_check_params) {
    std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Error: " << exception_check_params.what() << std::endl;
    bpp::quit(3);
  }

  //return 0;
}