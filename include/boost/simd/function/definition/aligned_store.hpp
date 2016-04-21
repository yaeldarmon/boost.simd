//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_ALIGNED_STORE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_ALIGNED_STORE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/as.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, aligned_store_, boost::dispatch::abstract_<aligned_store_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, aligned_store_);
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::aligned_store_,aligned_store);

} }

#endif
