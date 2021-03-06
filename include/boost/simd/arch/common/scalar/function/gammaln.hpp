//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_GAMMALN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_GAMMALN_HPP_INCLUDED

#include <boost/simd/function/std.hpp>
#include <boost/simd/arch/common/detail/generic/gammaln_kernel.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/invpi.hpp>
#include <boost/simd/constant/logpi.hpp>
#include <boost/simd/constant/logsqrt2pi.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/dec.hpp>
#include <boost/simd/function/scalar/floor.hpp>
#include <boost/simd/function/scalar/fma.hpp>
#include <boost/simd/function/scalar/inc.hpp>
#include <boost/simd/function/scalar/is_eqz.hpp>
#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/function/scalar/rec.hpp>
#include <boost/simd/function/scalar/sinpi.hpp>
#include <boost/simd/function/scalar/sqr.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( gammaln_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::single_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0) const BOOST_NOEXCEPT
    {
      A0 Maxgammaln = Constant<A0, 0x7bc3f8eaUL>(); //2.035093e36f
      if ((a0 > Maxgammaln) || bs::is_eqz(a0) ) return bs::Inf<A0>();
      A0 x = a0;
      A0 q = bs::abs(x);
      if( x < 0.0f )
      {
        if(q > Maxgammaln) return Nan<A0>();
        A0 w = gammaln_pos(q);
        A0 p =  bs::floor(q);
        if (p == q) return bs::Inf<A0>();
        A0 z = q - p;
        if( z > bs::Half<A0>() )
        {
          p += bs::One<A0>();
          z = p-q;
        }
        z = q*bs::sinpi(z);
        if( bs::is_eqz(z) ) return bs::Inf<A0>();
        return -bs::log(Invpi<A0>()*bs::abs(z))-w;
      }
      else
      {
        return gammaln_pos(x);
      }
    }
  private:
    static /*BOOST_FORCEINLINE*/ A0 gammaln_pos(A0 x) BOOST_NOEXCEPT
    {
      if( x < 6.5f )
      {
        A0 z = One<A0>();
        A0 tx = x;
        A0 nx = Zero<A0>();
        if( x >= 1.5f )
        {
          while( tx > 2.5f )
          {
            nx = dec(nx);
            tx = x + nx;
            z *=tx;
          }
          x += nx - Two<A0>();
          A0 p = x * detail::gammaln_kernel<A0>::gammalnB(x);
          return p+bs::log(z);

        }
        if( x >= 1.25f )
        {
          z *= x;
          x =  dec(x);
          A0 p = x *  detail::gammaln_kernel<A0>::gammalnB(x);
          return p-bs::log(z);
        }
        if( x >= 0.75f )
        {
          x = dec(x); //-= 1.0f;
          return x * detail::gammaln_kernel<A0>::gammalnC(x);
        }
        while( tx < 1.5f )
        {
          if(is_eqz(tx) ) return Inf<A0>();
          z *=tx;
          nx = inc(nx);
          tx = x + nx;
        }
        x += nx - Two<A0>();
        A0 p = x *  detail::gammaln_kernel<A0>::gammalnB(x);
        return p-log(z);
      }
      A0 q = fma(( x - 0.5f ), bs::log(x), Logsqrt2pi<A0>() - x);
      if( x <= 1.0e4f )
      {
        A0 z = rec(x);
        A0 p = sqr(z);
        q = fma(z, detail::gammaln_kernel<A0>::gammaln2(p), q);
      }
      return q;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( gammaln_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::double_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0) const BOOST_NOEXCEPT
    {
      A0 Maxgammaln = Constant<A0, 0x7f574c5dd06d2516ULL>();
      if ((a0 == bs::Inf<A0>()) || bs::is_eqz(a0) ) return bs::Inf<A0>(); //2.556348e305
      A0 x = a0;
      A0 q = bs::abs(x);
      if(x > Maxgammaln) return Inf<A0>();
      if( x < -34.0 )
      {
        if(q > Maxgammaln) return Nan<A0>();
        A0 w = gammaln_pos(q);
        A0 p =  bs::floor(q);
        if (p == q) return bs::Inf<A0>();
        A0 z = q - p;
        if( z > bs::Half<A0>() )
        {
          p += bs::One<A0>();
          z = p-q;
        }
        z = q*bs::sinpi(z);
        if( bs::is_eqz(z) ) return bs::Inf<A0>();
        return Logpi<A0>()-bs::log(z)-w;
      }
      else
      {
        return gammaln_pos(x);
      }
    }
  private:
    static /*BOOST_FORCEINLINE*/ A0 gammaln_pos(A0 x) BOOST_NOEXCEPT
    {
      if( x < 13.0 )
      {
        A0 z = One<A0>();
        A0 p = Zero<A0>();
        A0 u = x;
        while( u >= 3.0 )
        {
          p -= 1.0;
          u = x + p;
          z *= u;
        }
        while( u < 2.0 )
        {
          if( u == 0.0 )  return Inf<A0>();
          z /= u;
          p += 1.0;
          u = x + p;
        }
        z = bs::abs(z);
        if( u == 2.0 ) return( bs::log(z) );
        p -= 2.0;
        x = x + p;
        p = x * detail::gammaln_kernel<A0>::gammaln1(x);
        return bs::log(z) + p ;
      }
      A0 q = fma(( x - 0.5 ), bs::log(x), Logsqrt2pi<A0>()-x);
      if( x > 1.0e8 ) return q;

      A0 p = rec(sqr(x));
      q += detail::gammaln_kernel<A0>::gammalnA(p)/x;
      return q;
    }
  };
  BOOST_DISPATCH_OVERLOAD ( gammaln_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0, A0&sgn) const BOOST_NOEXCEPT
    {
      sgn = signgam(a0);
      return std::lgamma(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( gammaln_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bs::std_tag
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0, std_tag const&) const BOOST_NOEXCEPT
    {
      return std::lgamma(a0);
    }
  };
} } }


#endif
