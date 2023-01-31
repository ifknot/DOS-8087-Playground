#ifndef TEST_NPX_H
#define TEST_NPX_H

#include <iostream>
#include <cassert>

#include "math/is_installed_npx.h"

#define EXIT_SUCCESS 0

namespace test {

	int run() {

		int exit = EXIT_SUCCESS;
		std::cout << "test all...\n";
		{
			std::cout << "test is_installed_npx\n";
			assert(math::is_installed_npx());
		}
		return exit;

	}

}

#endif