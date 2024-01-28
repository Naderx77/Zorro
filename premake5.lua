workspace  "Zorro"
  
architecture "x64"

configurations {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Zorro"
  location "Zorro"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "%{prj.name}/vendor/spdlog/include",
    "%{prj.name}/src"
  }

  filter "system:windows"
    cppdialect "C++20"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "ZR_PLATFORM_WINDOWS",
      "ZR_BUILD_DLL"
    }
      
    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

  filter "configurations:Debug"
    defines "ZR_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "ZR_RELEASE"
    optimize "On"
  
  filter "configurations:Dist"
    defines "ZR_DIST"
    optimize "On"


project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"
  
  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
  
  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "Zorro/vendor/spdlog/include",
    "Zorro/src"
  }

  links
  {
    "Zorro"
  }
  
  filter "system:windows"
    cppdialect "C++20"
    staticruntime "On"
    systemversion "latest"

  defines
  {
    "ZR_PLATFORM_WINDOWS"
  }
  
  filter "configurations:Debug"
    defines "ZR_DEBUG"
    symbols "On"
  
  filter "configurations:Release"
    defines "ZR_RELEASE"
    optimize "On"
  
  filter "configurations:Dist"
    defines "ZR_DIST"
    optimize "On"