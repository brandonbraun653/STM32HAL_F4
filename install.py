import os
import platform
import subprocess


def install():
    """
    Installs the STM32 HAL. It's so basic that it won't tell you if it fails!
    Uses the default install directory specified in the cmake file.
    :return:
    """
    current_dir = os.path.dirname(os.path.realpath(__file__))
    build_dir = os.path.join(current_dir, "build")

    if not os.path.isdir(build_dir):
        os.makedirs(build_dir)

    # Assign the generator used based on the platform we are running on
    if platform.system() == "Windows":
        generator_target = "MinGW Makefiles"
        build_command = "mingw32-make.exe"
    elif platform.system() == "Linux":
        generator_target = "Unix Makefiles"
        build_command = "make"
    else:
        generator_target = ""
        build_command = ""

    command_list = ["cmake -G\"{}\" -DCMAKE_BUILD_TYPE=Release ../".format(generator_target),
                    "{} install".format(build_command),
                    "cmake -G\"{}\" -DCMAKE_BUILD_TYPE=Debug ../".format(generator_target),
                    "{} install".format(build_command)
                    ]

    for command in command_list:
        print("Executing command: {}".format(command))
        stdout, stderr = subprocess.Popen(command, cwd=build_dir, shell=True).communicate()

        print(stdout)
        if stderr:
            print(stderr)


if __name__ == "__main__":
    install()
