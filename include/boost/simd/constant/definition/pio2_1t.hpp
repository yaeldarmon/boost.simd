//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_PIO2_1T_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_PIO2_1T_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct pio2_1t_ : boost::dispatch::constant_value_<pio2_1t_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,pio2_1t_,boost::dispatch::constant_value_<pio2_1t_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0X37354443, 0X3DD0B4611A626331LL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,pio2_1t_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::pio2_1t_,pio2_1t);
  }

  template<typename T> BOOST_FORCEINLINE auto Pio2_1t()
  BOOST_NOEXCEPT_DECLTYPE(detail::pio2_1t( boost::dispatch::as_<T>{}))
  {
    return detail::pio2_1t( boost::dispatch::as_<T>{} );
  }
} }

#endif
