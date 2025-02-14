from conan import ConanFile

from conan.tools.cmake import cmake_layout
class deps(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    def requirements(self):
        self.requires("libmysqlclient/8.1.0")
        self.requires("nlohmann_json/3.11.3")
        self.requires("spdlog/1.13.0")
        
        #self.requires("cpr/1.11.0")
    def layout(self):
        cmake_layout(self)
    