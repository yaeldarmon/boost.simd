//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_LTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LTZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_ltz capabilities

    Returns @ref True or @ref False according x is less than @ref Zero or not.

    @par Semantic:

    @code
    as_logical_t<T> r = is_ltz(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = x < 0;
    @endcode

  **/
  const boost::dispatch::functor<tag::is_ltz_> is_ltz = {};
} }
#endif

#include <boost/simd/function/scalar/is_ltz.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>

#endif
