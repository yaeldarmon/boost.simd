//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/iterator/aligned_input_iterator.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <vector>

template <typename T>
using allocator = boost::alignment::aligned_allocator<T>; 

STF_CASE_TPL("types", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::aligned_input_iterator;
  using boost::simd::pack;

  STF_TYPE_IS( typename iterator_traits< aligned_input_iterator<T*> >::value_type
                  , (pack<T>)
                  );
}

STF_CASE_TPL("distance", STF_NUMERIC_TYPES)
{
  using boost::simd::aligned_input_iterator;
  using boost::simd::aligned_input_begin;
  using boost::simd::aligned_input_end;
  using boost::simd::pack;

  std::vector<T, allocator<T> > data(pack<T>::static_size*3);

  typedef typename std::vector<T, allocator<T> >::iterator it_t;

  aligned_input_iterator<it_t> b = aligned_input_begin(data.begin());
  aligned_input_iterator<it_t> e = aligned_input_end(data.end());

  STF_EQUAL( std::distance(b,e), 3);
}

/* Uncomment if/when STF_ASSERT is implemented
STF_CASE_TPL("aligned_constraint", STF_NUMERIC_TYPES)
{
  using boost::simd::aligned_input_iterator;
  using boost::simd::aligned_input_begin;
  using boost::simd::aligned_input_end;
  using boost::simd::pack;

  std::vector<T, allocator<T> > data(pack<T>::static_size*3);

  STF_ASSERT( aligned_input_begin(data.begin()+1) );
  STF_ASSERT( aligned_input_end(data.end()-1)     );
}
*/

STF_CASE_TPL("iteration", STF_NUMERIC_TYPES)
{
  using boost::simd::aligned_input_iterator;
  using boost::simd::aligned_input_begin;
  using boost::simd::aligned_input_end;
  using boost::simd::pack;
  using boost::simd::splat;

  std::vector< pack<T> >           ref(3);
  std::vector<T, allocator<T> > data(pack<T>::static_size*3);

  typedef typename std::vector<T, allocator<T> >::iterator it_t;

  for(std::size_t i=0;i<data.size();i++)
    data[i] = i/pack<T>::static_size+1;

  for(std::size_t i=0;i<ref.size();i++)
    ref[i] = splat< pack<T> >(i+1);

  aligned_input_iterator<it_t> b = aligned_input_begin(data.begin());

  STF_EQUAL( *b++, ref[0] );
  STF_EQUAL( *b++, ref[1] );
  STF_EQUAL( *b++, ref[2] );
}
