//
// Created by wenluyang on 2022/11/20.
//

#ifndef QTVIEWBDF_OCCDOCUMENT_H
#define QTVIEWBDF_OCCDOCUMENT_H

// document for OCC to manage data on backend
#include <string>
using std::string;

namespace MK {
    class AbstractFileReader;
    class FEMInfo;
}

namespace PI {
    class PrimitiveInfo;
}

class OCCDocument {

public:

    OCCDocument();
    ~OCCDocument();

    int load(const string& filepath, const string& filename);

    PI::PrimitiveInfo* getpriinfo()  {return m_priinfo;};

    const PI::PrimitiveInfo* getpriinfo() const {return m_priinfo;}
protected:

    void clear();

protected:
    string m_strfile;
    string m_strpath;

    MK::AbstractFileReader* m_reader;
    MK::FEMInfo* m_feminfo;
    PI::PrimitiveInfo* m_priinfo;
};


#endif //QTVIEWBDF_OCCDOCUMENT_H
