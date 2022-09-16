#include <cassert>
#include <tuple>

#include "array_transform.h"

using namespace array_transform;

namespace
{
  char f( const int i ){ return 'a' + i; }

  char g( const int i ){ return 'a' + i; }
  int g( const char c ){ return c - 'a'; }

  struct H
  {
    char operator()( const int i ) const { return 'a' + i; }
    int operator()( const char c ) const { return c - 'a'; }
  };

  void empty_tuple()
  {
    static_assert( std::is_same_v< decltype( transform( std::tuple<>{}, &f ) ), std::tuple<> > );
  }

  void simple_tuple()
  {
    const auto transformed = transform( std::tuple{ 0, 'b', 2, 'd' }, []( const auto &t ){ return g( t ); } );
    const std::tuple expectation{ 'a', 1, 'c', 3 };

    static_assert( std::is_same_v< decltype( transformed ), decltype( expectation ) > );
    assert( transformed == expectation );
  }

  void functor_test()
  {
    const auto transformed = transform( std::tuple{ 'a', 1, 'c', 3 }, H{} );
    const std::tuple expectation{ 0, 'b', 2, 'd' };

    static_assert( std::is_same_v< decltype( transformed ), decltype( expectation ) > );
    assert( transformed == expectation );
  }
}

int main()
{
  empty_tuple();
  simple_tuple();
  functor_test();
}
