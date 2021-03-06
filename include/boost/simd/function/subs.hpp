//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SUBS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SUBS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing subs capabilities

    Computes the saturated difference of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = subs(x, y);
    @endcode

    This function coincides with @ref minus for floating point parameters.
    For integral type, it is similar to:

    @code
    T r = (x-y > Valmax) ? Valmax : (x-y < Valmin ? Valmin : x-y);
    @endcode

  **/
  const boost::dispatch::functor<tag::subs_> subs = {};

} }
#endif

#include <boost/simd/function/scalar/subs.hpp>
#include <boost/simd/function/simd/subs.hpp>

#endif
