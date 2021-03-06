//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/group.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/shrai.hpp>
#include <boost/simd/function/simd/split_multiplies.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/dispatch/meta/upgrade.hpp>

/* No native groups for 64-bit SSE;
 * we use bit tricks instead of calling saturate. */

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( multiplies_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return _mm_mul_pd(a0,a1);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( multiplies_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::ints8_<A0>, bs::sse_>
                          , bs::pack_<bd::ints8_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A0 & a1 ) const BOOST_NOEXCEPT
    {
     using type = bd::upgrade_t<A0,signed>;
     type mask = Ratio<type,0x00FF>();
     return _mm_or_si128 ( _mm_and_si128(mask, _mm_mullo_epi16(a0,a1))
                          , _mm_slli_epi16
                            ( _mm_and_si128 ( mask
                                            , _mm_mullo_epi16
                                              ( _mm_srli_epi16(a0, 8)
                                              , _mm_srli_epi16(a1, 8)
                                              )
                                            )
                            , 8
                            )
                          );
    }
  };

  BOOST_DISPATCH_OVERLOAD ( multiplies_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::ints16_<A0>, bs::sse_>
                          , bs::pack_<bd::ints16_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A0 & a1 ) const BOOST_NOEXCEPT
    {
       return _mm_mullo_epi16(a0, a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( multiplies_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                         )
  {

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"
#endif // __clang__

    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return _mm_or_si128(
                    _mm_and_si128(
                       _mm_mul_epu32(a0,a1),
                       _mm_setr_epi32(0xffffffff,0,0xffffffff,0)
                    )
                  , _mm_slli_si128(
                        _mm_and_si128(
                            _mm_mul_epu32( _mm_srli_si128(a0,4)
                                         , _mm_srli_si128(a1,4)
                                         )
                          , _mm_setr_epi32(0xffffffff,0,0xffffffff,0)
                        )
                      , 4
                    )
             );
    }

#ifdef __clang__
#pragma clang diagnostic pop
#endif // __clang__

  };
} } }

#endif
