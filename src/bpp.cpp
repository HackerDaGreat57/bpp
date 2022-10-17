//I am currently working on the JavaScript version. Please refer to https://github.com/HackerDaGreat57/bpp#update-order for more information.

//bpp.cpp: The source code for Blender++ v0.0.0.126.
//Make sure to install the Bookmarks extention the Visual Studio Code Marketplace. (The one with the blue icon.)

//Defines
#define GLFW_DLL

//Includes
#include "include/glad.h"
#include <GLFW/glfw3.h>

#include <boost/program_options.hpp>

#include <ncursesw/curses.h>

#include <iostream>
#include <iterator>
#include <string_view>
#include <string>
#include <cstring>

//Platform-specific includes
#ifdef _WIN32
#include <windows.h>
#endif

//The Blender++ namespace tree
namespace bpp {
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
      //Basically just copypasta the foreground colors when we finish with those (and change all of the '[38's to '[48's)
    }
  }

  namespace tests {
    void color(void);
  }

  namespace functions {
    void check_params(int pargc, char **pargv);

    namespace gl {
      void framebuffer_size_callback(GLFWwindow *window, int width, int height);
      void process_input(GLFWwindow *window);
    }
  }

  void start(signed short int renderer);
  void quit(short int retval);
}

int main(int argc, char *argv[]) {
  #ifdef _WIN32 //Windows-specific code in order to enable 24-bit console coloring
  HANDLE win_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  HANDLE win_hConsole_custom = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
  SetConsoleActiveScreenBuffer(win_hConsole_custom);
  DWORD win_consoleMode = 0;
  GetConsoleMode(win_hConsole_custom, &win_consoleMode);
  win_consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(win_hConsole_custom, win_consoleMode);
  #endif //See https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797 or _reference/ANSI.md

  bpp::functions::check_params(argc, argv);

  //The code ahead will only run if the user didn't specify any parameters.
  bpp::start(-1);
  return 0;
}

void bpp::start(signed short int renderer) {
  switch (renderer) {
    case -1: //No arguments
      initscr();
      
      #ifdef _WIN32
      printw("Please re-run Blender++ with the --renderer-cpu argument OR use (double-click) the start.bat script.\n\nPress any key to continue...");
      #else
      printw("Please re-run Blender++ with the --renderer-cpu argument OR use the start.sh script.\n\nPress any key to continue...");
      #endif

      refresh();
      getch();
      endwin();
      break;

    case 0: //CPU
      break;
    
    case 1: //Console
      break;
    
    case 2: //wxWidgets
      break;

    case 3: //Qt
      break;
    
    case 4: //win32
      break;

    case 5: //GDI
      break;

    case 6: //GDI+
      break;

    case 7: //OpenGL
      break;
    
    case 8: //Vulkan
      break;

    case 9: //Metal
      break;

    case 10: //Direct3D 9
      break;

    case 11: //Direct3D 10
      break;

    case 12: //Direct3D 11
      break;

    case 13: //Direct3D 12
      break;
  }
}

void bpp::tests::color(void) {
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
    case 4:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Blender++ terminated, returned an exception. (Honestly, no idea how to fix this one.)" << std::endl;
      break;
    default:
      std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Blender++ terminated with an unknown error." << std::endl;
      break;
  }

  exit(retval);
}

void bpp::functions::gl::process_input(GLFWwindow *window) { //Query GLFW whether relevant keys are pressed/released this frame and react accordingly
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true); //Escape obviously means "Quit".
  }
}

void bpp::functions::gl::framebuffer_size_callback(GLFWwindow *window, int width, int height) { //This gets called whenever the window gets resized
  glViewport(0, 0, width, height); //Make sure the viewport is the same size as the window.
}

void bpp::functions::check_params(int pargc, char **pargv) {
  short int errorcode;
  signed short int renderer;

  try {
    boost::program_options::options_description options_description("Blender++ v0.0.0.126 Help", 100);
    options_description.add_options()
      ("help", "Print help message (the thing you're reading right now)")
      ("errorhelp", "Print basic information about all error codes")
      ("errorcode", boost::program_options::value(&errorcode) , "Displays a longer description for a specific error code with possible solutions. Replace 'arg' with your error code\n") //`\n` to add a separator
      ("renderer-cpu", "Use the CPU renderer")
      ("renderer-console", "Use the ncursesw-based console renderer")
      ("renderer-wx", "Use the wxWidgets renderer")
      ("renderer-qt", "Use the Qt renderer")
      ("renderer-win32", "Use the win32 renderer (Windows only)")
      ("renderer-gdi", "Use the GDI renderer (Windows only)")
      ("renderer-gdiplus", "Use the GDI+ renderer (Windows only)")
      ("renderer-gl", "Use the OpenGL 4.6 renderer")
      ("renderer-vulkan", "Use the Vulkan 1.3 renderer")
      ("renderer-metal", "Use the Metal renderer (macOS only)")
      ("renderer-d3d9", "Use the Direct3D 9 renderer (Windows only)")
      ("renderer-d3d10", "Use the Direct3D 10 renderer (Windows only)")
      ("renderer-d3d11", "Use the Direct3D 11 renderer (Windows only)")
      ("renderer-d3d12", "Use the Direct3D 12 renderer (Windows only)\n")
      ("clr-test", "Test the color printing system to make sure that it works");

    boost::program_options::variables_map variables_map;
    boost::program_options::store(boost::program_options::parse_command_line(pargc, pargv, options_description), variables_map);
    boost::program_options::notify(variables_map);

    if (variables_map.count("renderer-cpu")) {
      bpp:start(0);
      bpp::quit(0);
    }

    if (variables_map.count("help")) {
      std::cout << options_description << std::endl;
      bpp::quit(0);
    }

    if (variables_map.count("errorhelp")) {
      std::cout << "There are different types of errors in Blender++. And it is generally good computer programming practice to assign an ID or code to every error. The types of errors in Blender++ are listed below. Run the application with \"--errorhelp {your error code here}\" to learn about possible solutions for your error." << std::endl;
      std::cout << "0: Success. Nothing to worry about." << std::endl;
      std::cout << "1: Failed to create GLFW window." << std::endl;
      std::cout << "2: Failed to initialize GLAD." << std::endl;
      std::cout << "3: Couldn't recognise an argument." << std::endl;
      std::cout << "4: Exception. This should never occur if you are not developing this application." << std::endl;
      std::cout << std::endl << "If you get any other kind of error, please try reinstalling Blender++. If none of these options work, you can reach out to me at HackerDaGreat57@gmail.com." << std::endl << std::endl;
      bpp::quit(0);
    }

    if (variables_map.count("errorcode")) {
      switch (errorcode) {
        case 0:
          std::cout << "Error 0: Success. Error 0 in any program always means success." << std::endl;
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
        case 4:
          std::cout << "Error 4: Exception. This should never occur if you are not developing this application, however you can file a bug report at https://github.com/hackerdagreat57/bpp/issues if you are an end-user." << std::endl;
          bpp::quit(0);

        default:
          std::cout << "Invalid error code. Try again with the right number this time." << std::endl;
          bpp::quit(0);
      }
    }

    if (variables_map.count("clr-test")) {
      bpp::tests::color();
      bpp::quit(0);
    }
  }

  catch(std::exception &exception_check_params) {
    std::cout << "{Blender++ Core} [" << __FILE__ << ":" << __LINE__ << "] Error: " << exception_check_params.what() << std::endl;
    bpp::quit(3);
  }
}
