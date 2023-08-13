#pragma once
#include <string>
#include <Windows.h>

namespace GLOBALS
{
	inline constexpr int WINDOW_SIZE_X = 575;
	inline const int ACTUAL_WINDOWS_SIZE_X = GetSystemMetrics(SM_CXSCREEN);
	inline const int ACTUAL_WINDOWS_SIZE_Y = GetSystemMetrics(SM_CYSCREEN);
	inline constexpr int COLUMN_MATRIX = 6;
	inline constexpr int ROW_MATRIX = 8;
	inline constexpr int FIGURE_SIZE_X = 9;
	inline constexpr int FIGURE_SIZE_Y = 5;
	inline const int MATRIX_BASE_X = ACTUAL_WINDOWS_SIZE_X / 240;
	inline const int MATRIX_BASE_Y = ACTUAL_WINDOWS_SIZE_Y / 87;
	inline const char* NODE_FIGURE[4][FIGURE_SIZE_Y] = {  "   │ │   ", "  _│ │_  ", " │     │ ", " │_____│ ", "         ",
												          "  ___    ", " │   │__ ", " │    __│", " │___│   ", "         ",
														  "  _____  ", " │     │ ", " │_   _│ ", "   │ │   ", "   │_│   ",
														  "    ___  ", " __│   │ ", "│__    │ ", "   │___│ ", "         " };
	inline const char* LINE_FIGURE[4][FIGURE_SIZE_Y] = {  "   │ │   ", "   │ │   ", "   │ │   ", "   │ │   ", "   │_│   ",
														  "         ", " _______ ", "│_______│", "         ", "         ",
														  "   │ │   ", "   │ │   ", "   │ │   ", "   │ │   ", "   │_│   ",
														  "         ", " _______ ", "│_______│", "         ", "         " };
	inline const char* CURVE_FIGURE[4][FIGURE_SIZE_Y] = { "   │ │   ", "   │ │__ ", "   │____│", "         ", "         ",
														  "         ", "    ____ ", "   │  __│", "   │ │   ", "   │_│   ",
														  "         ", " ____    ", "│__  │   ", "   │ │   ", "   │_│   ",
														  "   │ │   ", " __│ │   ", "│____│   ", "         ", "         " };
	inline const char* TRIPLE_FIGURE[4][FIGURE_SIZE_Y] = {"   │ │   ", " __│ │__ ", "│_______│", "         ", "         ",
														  "   │ │   ", "   │ │__ ", "   │  __│", "   │ │   ", "   │_│   ",
														  "         ", " _______ ", "│__   __│", "   │ │   ", "   │ │   ",
														  "   │ │   ", " __│ │   ", "│__  │   ", "   │ │   ", "   │_│   " };
	inline const char* QUADRUPLE_FIGURE[FIGURE_SIZE_Y] = { "   │ │   ", " __│ │__ ", "│__   __│", "   │ │   ", "   │_│   " };
}
 