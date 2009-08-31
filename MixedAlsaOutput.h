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

#ifndef MIXED_ALSA_OUTPUT_H
#define MIXED_ALSA_OUTPUT_H

#include <string>
#include <iostream>

extern "C" {
  #include <alsa/asoundlib.h>
}

using namespace std;

#include "exceptions.h"
#include "Sample.h"

#include "AlsaOutput.h"
#include "SoundOutput.h"

class MixerOutput;
class AnnoymeException;

class MixedAlsaOutput : public virtual SoundOutput
{
public:
  MixedAlsaOutput(const std::string &device);
  virtual ~MixedAlsaOutput();
  virtual void playSound(const Sample *sound);
  virtual void open();
  virtual void close();
private:
  void startThread() throw(AnnoymeException);
  void stopThread() throw(AnnoymeException);
  void run();
  static void* runObject(void *object);

private:
  SoundOutput *m_soundOutput;
  MixerOutput *m_mixer;
  pthread_t    m_thread;
};

#endif // MIXED_ALSA_OUTPUT_H
