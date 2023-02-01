#ifndef TEST_NPX_H
#define TEST_NPX_H

//#define NDEBUG

#include "test/macros.h"

#include "math/is_installed_npx.h"

namespace test {

	int run() {

		int exit = EXIT_SUCCESS;
		INFO("test all...\n");
		{
			INFO("test is_installed_npx\n");
			ASSERT(math::is_installed_npx(), "NPX not installed");
		}
		LOG(exit);
		return exit;

	}

}

#endif