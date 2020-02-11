
// Copyright (c) 2015-16 Tom Deakin, Simon McIntosh-Smith,
// University of Bristol HPC
//
// For full license terms please see the LICENSE file distributed with this
// source code

#pragma once

#include <iostream>
#include <stdexcept>

#include "Stream.h"

#include <openacc.h>

#define IMPLEMENTATION_STRING "OpenACC"

template <class T>
class ACCStream : public Stream<T>
{
  protected:
    // Size of arrays
    unsigned int array_size;
    // Device side pointers
    T *a;
    T *b;
    T *c;

  public:
    ACCStream(const unsigned int, T*, T*, T*, int);
    ~ACCStream();

    virtual float read() override;
    virtual float write() override;
    virtual float copy() override;
    virtual float add() override;
    virtual float mul() override;
    virtual float triad() override;
    virtual T dot() override;

    virtual void init_arrays(T initA, T initB, T initC) override;
    virtual void read_arrays(std::vector<T>& a, std::vector<T>& b, std::vector<T>& c) override;



};
