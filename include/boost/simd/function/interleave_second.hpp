//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_SECOND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing interleave_second capabilities

    Computes a vector from a combination of the two inputs.

    @par Semantic:

    For every parameters of type T0:

    @code
    T0 r = interleave_second(a,b);
    @endcode

    is equivalent to :

    @code
    r = [ a[n/2-1] b[n/2-1] a[n/2] b[n/2] ... a[n-1] b[n-1] ]
    @endcode

    with <tt> n = cardinal_of<T>::value </tt>

  **/
  const boost::dispatch::functor<tag::interleave_second_> interleave_second = {};
} }
#endif

#include <boost/simd/function/scalar/interleave_second.hpp>
#include <boost/simd/function/simd/interleave_second.hpp>

#endif
