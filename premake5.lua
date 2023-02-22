workspace "Flittermouse"
	configurations {"Debug", "Perf", "Dist"}
	architecture "x64"
	startproject "Training"

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Flittermouse"
location "Flittermouse"
	kind "SharedLib"
	language "C++"
	
	externalanglebrackets "on"
	externalwarnings "off"

	pchheader "FM_pch.h"
	pchsource "Flittermouse/source/FM_pch.cpp"

	files {"%{prj.name}/source/**.h", "%{prj.name}/source/**.cpp"}
	includedirs {"%{prj.name}/lib/spdlog/include", "%{prj.name}/source"}



	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")


	filter {"system:windows"}
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"
		defines {
			"FM_PLATFORM_WINDOWS",
			"FM_BUILD_DLL"

		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Training")
		}


	filter {"configurations:Debug"}
		defines {"FM_DEBUG"}
		symbols "On"


	filter {"configurations:Perf"}
		defines {"FM_PERF"}
		optimize "On"

	filter {"configurations:Debug"}
		defines {"FM_DEBUG"}
		optimize "On"

project "Training"
location "Training"
	kind "ConsoleApp"
	language "C++"

	externalanglebrackets "on"
	externalwarnings "off"

	files {"%{prj.name}/source/**.h", "%{prj.name}/source/**.cpp"}
	includedirs {
			"FlitterMouse/lib/spdlog/include",
			"Flittermouse/source"
	}

	links {
		"Flittermouse"
	}

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	filter {"system:windows"}
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"
		defines {
			"FM_PLATFORM_WINDOWS"
		}


	filter {"configurations:Debug"}
		defines {"FM_DEBUG"}
		symbols "On"


	filter {"configurations:Perf"}
		defines {"FM_PERF"}
		optimize "On"

	filter {"configurations:Debug"}
		defines {"FM_DEBUG"}
		optimize "On"