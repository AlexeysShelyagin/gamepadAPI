import os

Import("env")

lib_directory = os.path.dirname(os.path.realpath(__file__))

header_path = os.path.join(lib_directory, "..", "src", "UserSetup_override.h")

if not os.path.isfile(header_path):
    print(f"--- WARNING: Could not find override header at {header_path} ---")

global_env = DefaultEnvironment()

global_env.Append(
    CPPDEFINES=["USER_SETUP_LOADED"],
    CCFLAGS=["-include", f'"{header_path}"']
)

global_env.Append(CPPPATH=[os.path.join(lib_directory, "..", "src")])