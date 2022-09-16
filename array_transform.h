#pragma once

#include <array>
#include <cstddef>
#include <tuple>
#include <utility>

namespace array_transform
{
  template< typename F, std::size_t N, typename IN >
  auto transform( const std::array< IN, N > &in, F f )
  { return std::apply( [ &f ]( const auto &... in ){ return std::array{ f( in )... }; }, in ); }

  template< typename F, typename IN >
  auto transform( const std::array< IN, 0 > &in, F f )
  { return std::array< decltype( f( std::declval< IN >() ) ), 0 >{}; }

  template< typename F, typename... T >
  auto transform( const std::tuple< T... > &in, F f )
  { return std::apply( [ &f ]( const auto &... in ){ return std::tuple{ f( in )... }; }, in ); }

  template< typename F, typename T1, typename T2 >
  auto transform( const std::pair< T1, T2 > &in, F f )
  { return std::apply( [ &f ]( const auto &... in ){ return std::pair{ f( in )... }; }, in ); }
}
