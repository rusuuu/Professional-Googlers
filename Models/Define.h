#pragma once
#ifdef MODELS_EXPORTS
#define MODELS_API __declspec(dllexport)
#else
#define MODELS_API __declspec(dllimport)
#endif
