//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/int_splat.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check int_splat behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::int_splat;
  using boost::simd::Int_splat;

  STF_TYPE_IS(decltype(Int_splat<T>()), T);
  STF_EQUAL(Int_splat<T>(), T(1));
  STF_EQUAL(int_splat( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check int_splat behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::int_splat;
  using boost::simd::Int_splat;

  STF_TYPE_IS(decltype(Int_splat<T>()), T);
  STF_IEEE_EQUAL(Int_splat<T>(), T(1));
  STF_IEEE_EQUAL(int_splat( as(T{}) ), T(1));
}
