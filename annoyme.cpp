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

#include <string>
#include <cstdlib>

// OS specific headers
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xproto.h>
#include <X11/X.h>
#include <X11/extensions/Xevie.h>
#include <X11/Xutil.h>

using namespace std;

#include "Event.h"
#include "XevieInput.h"
#include "StaticConfiguration.h"
#include "Sample.h"
#include "SimpleWaveFileLoader.h"
#include "AlsaOutput.h"

#include "Annoyme.h"

int main(int argc, char **argv)
{
  Annoyme annoyme;
  annoyme.init();
  annoyme.run();
  annoyme.close();

  return EXIT_SUCCESS;
}
