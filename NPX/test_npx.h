#ifndef TEST_NPX_H
#define TEST_NPX_H

//#define NDEBUG

#include "test/macros.h"

#include "math/is_installed_npx.h"
#include "math/npx_array_tools.h"

namespace test {

	int run() {

		int exit = EXIT_SUCCESS;
		INFO("test all...\n");
		{
			INFO("test is_installed_npx\n");
			ASSERT(math::is_installed_npx(), "NPX not installed");
			{
				float a[] = { 3.544, 5.544, 6.544, 6.544 };
				LOG(math::sum_array_float(a, 4));
				ASSERT(math::sum_array_float(a, 4) == a[0] + a[1] + a[2] + a[3], "NPX fail");
				
			}
		}
		LOG(exit);
		return exit;

	}

}

#endif