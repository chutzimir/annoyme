/*
 * Copyright (c) 2009, Benjamin Peter <BenjaminPeter@arcor.de>
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
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES
 * LOSS OF USE, DATA, OR PROFITS OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <string>

using namespace std;

#include "InputEventHandler.h"
#include "Sample.h"
#include "SoundOutputAdapter.h"
#include "HandlerSoundOutput.h"

HandlerSoundOutput::HandlerSoundOutput(SoundOutputAdapter *output)
: m_output(output)
{
	
}

HandlerSoundOutput::~HandlerSoundOutput()
{
	
}

void HandlerSoundOutput::play(enum Sample::SampleType type)
{
	m_output->play(type);
} 

void HandlerSoundOutput::handleNormalKeyPressed()
{
	play(Sample::normalKeyPressed);
}

void HandlerSoundOutput::handleNormalKeyReleased()
{
	play(Sample::normalKeyReleased);
}

void HandlerSoundOutput::handleEnterPressed()
{
	play(Sample::enterPressed);
}

void HandlerSoundOutput::handleEnterReleased()
{
	play(Sample::enterReleased);
}

void HandlerSoundOutput::handleBackspacePressed()
{
	play(Sample::backspacePressed);
}

void HandlerSoundOutput::handleBackspaceReleased()
{
	play(Sample::backspaceReleased);
}
