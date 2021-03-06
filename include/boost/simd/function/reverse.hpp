//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REVERSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REVERSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing reverse capabilities

    returns a vector the elements of which are
    those of x in reverse order

    @par Semantic:

    For every parameter of type T

    @code
    T r = reverse(x);
    @endcode

    is similar to:

    @code
    T r = ;
    for(size_t i=0;i<cardinal_of<T>;++i)
    r[i] = x[cardinal_of<T>-i-1];
    @endcode

  **/
  const boost::dispatch::functor<tag::reverse_> reverse = {};
} }
#endif

#include <boost/simd/function/scalar/reverse.hpp>
#include <boost/simd/function/simd/reverse.hpp>

#endif
