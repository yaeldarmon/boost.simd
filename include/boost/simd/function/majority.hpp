//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAJORITY_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAJORITY_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing majority capabilities

    Returns @ref True if at least two inputs are not @ref Zero else @ref False.

    @par Semantic:

    @code
    as_logical_t<T> r = majority(x,y,z);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = (x!= 0)+(y!= 0)+(z!= 0) >= 2;
    @endcode

  **/
  const boost::dispatch::functor<tag::majority_> majority = {};
} }
#endif

#include <boost/simd/function/scalar/majority.hpp>
#include <boost/simd/function/simd/majority.hpp>

#endif
