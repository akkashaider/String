/* 
 * File:   test_driver.h
 * Author: akkas
 *
 * Created on December 9, 2014, 2:35 AM
 */

#ifndef TEST_DRIVER_H
#define	TEST_DRIVER_H
#include <vector>
#include <functional>
class test_driver
	{
	public:
		test_driver(void);
		~test_driver(void);

		void start_testing();

	private:
		void add_test();

		std::vector<std::function<void()> > test_list;
		int total_passed_tests;
		int total_failed_tests;
	};


#endif	/* TEST_DRIVER_H */
#ifdef NDEBUG
#define ASSERT(statement)
#else
#define ASSERT(statement)										\
															\
if(!(statement))													\
{														\
	std::cout <<__FUNCTION__<< "    failed"<<std::endl;\
        throw "test failed";\
}															\
else														\
{															\
	std::cout << __FUNCTION__ << "  passed" << std::endl;	\
}

#endif

