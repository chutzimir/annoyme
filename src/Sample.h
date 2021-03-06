/*
 * Copyright (c) 2008, Benjamin Peter <BenjaminPeter@arcor.de>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the author nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Benjamin Peter ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Benjamin Peter BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <iostream>
using namespace std;

#ifndef SAMPLE_H
#define SAMPLE_H

class Sample
{
public:
  enum SampleType
  {
    invalidType,
    defaultType,
    normalKeyPressed,
    normalKeyReleased,
    enterPressed,
    enterReleased,
    backspacePressed,
    backspaceReleased,
  };
  
  enum SampleFormat
  {
    invalidFormat,
    PCM,
  };

public:
  static const enum SampleType getSampleType(const string name)
  {
    if (name == "normalKeyPressed") {
      return normalKeyPressed;
    }
    else if (name == "normalKeyReleased") {
      return normalKeyReleased;
    }
    else if (name == "enterPressed") {
      return enterPressed;
    }
    else if (name == "enterReleased") {
      return enterReleased;
    }
    else if (name == "backspacePressed") {
      return backspacePressed;
    }
    else if (name == "backspaceReleased") {
      return backspaceReleased;
    }
    else {
      return invalidType;
    }
  }

public:
  Sample()
  : m_format(invalidFormat)
  , m_rate(0)
  , m_data(0)
  , m_size(0)
  , m_type(invalidType)
  {

  }

  virtual ~Sample()
  {

  }

public:
  void setFormat(SampleFormat new_var)
  {
    m_format = new_var;
  }

  SampleFormat getFormat() const
  {
    return m_format;
  }

  void setRate(int new_var)
  {
    m_rate = new_var;
  }

  int getRate() const
  {
    return m_rate;
  }

  void setData(char* new_var)
  {
    m_data = new_var;
  }

  char* getData() const
  {
    return m_data;
  }

  void setFilePath(const string &new_var)
  {
    m_filePath = new_var;
  }

  string getFilePath() const
  {
    return m_filePath;
  }

  inline void setName(const string &new_var)
  {
    m_name = new_var;
  }
  
  inline const string getName() const
  {
    return m_name;
  }

  void setType(const enum SampleType &new_var)
  {
    m_type = new_var;
  }

  SampleType getType() const
  {
    return m_type;
  }

  void setSize(unsigned int new_var)
  {
    m_size = new_var;
  }

  unsigned int getSize() const
  {
    return m_size;
  }

private:
  SampleFormat  m_format;
  int           m_rate;
  char*         m_data;
  unsigned long m_size;
  SampleType    m_type;
  string        m_name;
  string        m_filePath;
};

#endif // SAMPLE_H
