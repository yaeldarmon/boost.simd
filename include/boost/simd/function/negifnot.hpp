//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGIFNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGIFNOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing negifnot capabilities

    The function returns -x if cond is @ref False and x otherwise.

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T1 r = negifnot(cond,x);
    @endcode

    is similar to:

    @code
    T r = cond ? x : -x;
    @endcode

  **/
  const boost::dispatch::functor<tag::negifnot_> negifnot = {};
} }
#endif

#include <boost/simd/function/scalar/negifnot.hpp>
#include <boost/simd/function/simd/negifnot.hpp>

#endif
