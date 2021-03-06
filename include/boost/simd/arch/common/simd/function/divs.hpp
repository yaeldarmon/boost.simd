//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DIVS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DIVS_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/simd/bitwise_or.hpp>
#include <boost/simd/function/simd/bitwise_xor.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/if_zero_else_one.hpp>
#include <boost/simd/function/simd/inc.hpp>
#include <boost/simd/function/simd/is_eqz.hpp>
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/simd/logical_and.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/shift_right.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(divs_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        return a0/a1;
      }
   };

   BOOST_DISPATCH_OVERLOAD(divs_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::uint_<A0>, X>
                          , bs::pack_<bd::uint_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        auto iseqza1 = is_eqz(a1);
        const A0 aa1 = if_else(iseqza1, One<A0>(), a1);
        const A0 aa0 = if_else(iseqza1, genmask(a0), a0);
        return aa0/aa1;
      }
   };

   BOOST_DISPATCH_OVERLOAD(divs_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::int_<A0>, X>
                          , bs::pack_<bd::int_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        using sA0 = bd::scalar_of_t<A0>;
        auto iseqza1 = is_eqz(a1);
        // replace valmin/-1 by (valmin+1)/-1
        A0 x = a0 + if_zero_else_one(inc(a1) | (a0 + Valmin<A0>()));
        // negative -> valmin
        // positive -> valmax
        const A0 x2 = bitwise_xor(Valmax<A0>(), shift_right(x, sizeof(sA0)*CHAR_BIT-1));
        x = if_else(logical_and(iseqza1, is_nez(x)), x2, x);
        const A0 y = if_else(iseqza1, One<A0>(), a1);
        return x/y;
      }
   };

} } }

#endif

