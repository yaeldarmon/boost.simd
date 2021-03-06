//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SPLIT_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLIT_MULTIPLIES_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing split_multiplies capabilities

    SIMD register type-based multiplies and split

    @c split_multiplies multiplies two x-bit SIMD registers and returns two 2x-bit registers
    each having half the cardinal of the original inputs.

  **/
  const boost::dispatch::functor<tag::split_multiplies_> split_multiplies = {};
} }
#endif

#include <boost/simd/function/scalar/split_multiplies.hpp>
#include <boost/simd/function/simd/split_multiplies.hpp>

#endif
