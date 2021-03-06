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

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class AnnoymeException: public exception
{
public:
	AnnoymeException(string msg = "") throw () :
		m_message(msg)
	{

	}
	;

	virtual ~AnnoymeException() throw ()
	{
	}
	;

	virtual const char* what() const throw ()
	{
		return m_message.c_str();
	}

protected:

	string m_message;
};

class UnknownOptionException: public AnnoymeException
{
public:

	UnknownOptionException(string name) throw () :
		AnnoymeException(string("Unknown option requested: ") + name), m_name(name)
	{

	}

	virtual ~UnknownOptionException() throw ()
	{
	}
	;

protected:

	string m_name;
};

class FileNotFoundException: public AnnoymeException
{
public:

	FileNotFoundException(string path, string purpose = string()) throw () :
		AnnoymeException(string("Could not open file: ") + path), m_path(path),
				m_purpose(purpose)
	{
		if (purpose.size() != 0) {
			m_message.append(" (" + m_purpose + ")");
		}
	}

	virtual ~FileNotFoundException() throw ()
	{
	}
	;

protected:

	string m_path;
	string m_purpose;
};

class XevieExtensionNotInstalledException: public AnnoymeException
{
public:

	XevieExtensionNotInstalledException() throw () :
		AnnoymeException(string("Xevie Extension is not installed or enabled."))
	{

	}

	virtual ~XevieExtensionNotInstalledException() throw ()
	{
	}
	;
};

class XDisplayException: public AnnoymeException
{
public:

	XDisplayException() throw () :
		AnnoymeException(string("Could not open X display."))
	{

	}

	virtual ~XDisplayException() throw ()
	{
	}
	;
};

class UnknownEventReceived: public AnnoymeException
{
public:

	UnknownEventReceived() throw () :
		AnnoymeException(string("Xevie Extension is not installed or enabled."))
	{

	}

	virtual ~UnknownEventReceived() throw ()
	{
	}
	;
};

class AnnoyErrnoException: public AnnoymeException
{
public:

	AnnoyErrnoException(string msg, const string &subject, int errnum) throw () :
		errnum(errnum)
	{
		msg += ": ";
		msg += subject;
		msg += ": ";
		msg += string(strerror(errnum));
		m_message = msg;
	}

	virtual ~AnnoyErrnoException() throw ()
	{
	}
	;

private:

	int errnum;
};

class SoundOutputException: public AnnoymeException
{
public:

	SoundOutputException(const string &msg) throw () :
		AnnoymeException(msg)
	{

	}

	virtual ~SoundOutputException() throw ()
	{
	}
	;
};

class AlsaOutputException: public SoundOutputException
{
public:

	AlsaOutputException(const string &msg) throw () :
		SoundOutputException(msg)
	{

	}

	virtual ~AlsaOutputException() throw ()
	{
	}
	;
};

class InvalidNameException: public AnnoymeException
{
public:

	InvalidNameException(const string &msg, const string &name) throw () :
		AnnoymeException(msg + ": " + name)
	{

	}

	virtual ~InvalidNameException() throw ()
	{
	}
	;
};

class IllegalArgumentException : public AnnoymeException
{
public:

	IllegalArgumentException(const string &msg) throw () :
		AnnoymeException(msg)
	{

	}

	virtual ~IllegalArgumentException() throw ()
	{
	}
	;
};

#endif // EXCEPTIONS_H
