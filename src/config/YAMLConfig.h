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

#ifndef YAMLCONFIG_H
#define YAMLCONFIG_H

class UnknownOptionException;
class FileNotFoundException;
class AnnoymeException;
class FileUtil;

class YAMLConfig: public BasicConfiguration
{
public:
	YAMLConfig(const std::string &resourcePath = std::string(), const std::string &configFileName = std::string());

	/**
	 * @param fileUtil, memory responsibility will be given to YAMLConfig
	 */
	YAMLConfig(const std::string &resourcePath, const std::string &configFileName,
			FileUtil* fileUtil);
	virtual ~YAMLConfig();
	virtual void init() throw (FileNotFoundException, AnnoymeException);
	virtual std::string getNormalized(const std::string &path)
			throw (UnknownOptionException);
	void setConfigFilePath(const std::string &path);
	std::string getConfigFilePath() const;
	void setResourcePath(const std::string &path);
	std::string getResourcePath() const;

private:
	std::string m_resourcePath;
	std::string m_configFilePath;
	std::map<std::string, std::string> m_values;
	FileUtil* m_fileUtil;

private:
	void createDefault() throw (AnnoymeException);
};

#endif // YAMLCONFIG_H
