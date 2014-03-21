#pragma once

#ifdef SKULLENGINE_EXPORT
# define SKULLENGINE_API __declspec(dllexport)
#else
# define SKULLENGINE_API __declspec(dllimport)
#endif

