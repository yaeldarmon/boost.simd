//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_LE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_LE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing compare_le capabilities

    Returns a logical scalar that is the result of the lexicographic
    test for <= on all elements of the entries

    It is probably not what you wish. Have a look to @ref is_less_equal

    This is a convenient alias of @ref compare_less_equal
  **/
  const boost::dispatch::functor<tag::compare_le_> compare_le = {};
} }
#endif

#include <boost/simd/function/scalar/compare_less_equal.hpp>
#include <boost/simd/function/simd/compare_le.hpp>

#endif
