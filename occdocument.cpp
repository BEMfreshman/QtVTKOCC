//
// Created by wenluyang on 2022/11/20.
//

#include "occdocument.h"

#include "AbstractFileReader.h"
#include "NASTRANFileReader.h"
#include "FEMInfo.h"
#include "PrimitiveInfo.h"

#include "VUKernelLog.h"

OCCDocument::OCCDocument() :
    m_reader(nullptr),m_feminfo(nullptr),m_priinfo(nullptr)
{

}

OCCDocument::~OCCDocument() {
    clear();
}

int OCCDocument::load(const string &filepath, const string &filename) {

    clear();

    m_strfile = filename;
    m_strpath = filepath;

    try {
        m_reader = new MK::NASTRANFileReader(filepath, filename);
    }
    catch (std::runtime_error& e) {
        static VU::VUKernelLog& log = VU::VUKernelLog::GetInstance();

        log.WriteLog(e.what());
        return 1;
    }

    m_feminfo = new MK::FEMInfo(m_reader);
    m_priinfo = new PI::PrimitiveInfo(m_feminfo);

    return 0;
}

void OCCDocument::clear() {
    delete m_reader;
    delete m_feminfo;
    delete m_priinfo;
}
