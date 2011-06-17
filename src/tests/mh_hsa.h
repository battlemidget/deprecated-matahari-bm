/*
 * mh_hs.h: dns srv high availability test 
 *
 * Copyright (C) 2011 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 * Author: Adam Stokes <astokes@fedoraproject.org>
 */


#ifndef __MH_HSA_UNITTEST_H
#define __MH_HSA_UNITTEST_H

#include <string.h>
#include <stdlib.h>
#include <cxxtest/TestSuite.h>

extern "C" {
#include "mh_test_utilities.h"
#include "matahari/dnssrv.h"
};

using namespace std;

class MhHsaSuite : public CxxTest::TestSuite
{
 public:
     std::stringstream infomsg;

     void testSrvLookup(void)
     {
         int ret;
         char target[MAX_NAME_LEN];
         const char *host = "_matahari._tcp.matahariproject.org";

         if ((ret = mh_srv_lookup(host, target)) == 0) {
             infomsg << "SRV record: " << target;
             TS_TRACE(infomsg.str());
             TS_ASSERT((mh_test_is_match("^qpid.*matahariproject\\.org$",
                                         target)) >= 0);
         }
     }
};

#endif