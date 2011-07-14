#ifndef __MH_API_NETWORK_UNITTEST_H
#define __MH_API_NETWORK_UNITTEST_H
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <sys/stat.h>
#include <dirent.h>
#include <cxxtest/TestSuite.h>

extern "C" {
#include "matahari/sysconfig.h"
#include <glib.h>
#include "mh_test_utilities.h"
};

using namespace std;

class MhApisysconfigSuite : public CxxTest::TestSuite
{
 public:

    void testIsConfigured(void)
    {
        const char *uri = "http://matahariproject.org/atom.xml";
        // TS_ASSERT((mh_run_puppet(uri, 0, REMOTE)) == 0);
        mh_run_puppet(uri, 0, REMOTE);
    }
};

#endif
