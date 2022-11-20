#ifndef OCCVIEW_H
#define OCCVIEW_H

#include <QWidget>
#include <AIS_InteractiveContext.hxx>
#include <memory>

#include <string>

using std::string;
using std::shared_ptr;
using std::make_shared;
class OCCDocument;

class OCCView : public QWidget
{
    Q_OBJECT
public:
    explicit OCCView(QWidget *parent = nullptr);
    ~OCCView() override = default;

    [[nodiscard]] const Handle(AIS_InteractiveContext)& getContext() const;

public:
    void load(const string& filePath, const string& fileName) ;


    void fitAll(void);

protected:
    [[nodiscard]] QPaintEngine* paintEngine() const override;

    void paintEvent(QPaintEvent* ev) override;
    void resizeEvent(QResizeEvent* ev) override;

    // mouse event
    //virtual void mousePressEvent(QMouseEvent* ev) override;

protected:
    void init(void);

private:
    Handle(V3d_Viewer) m_v3dviewer;
    Handle(V3d_View)   m_v3dview;
    Handle(AIS_InteractiveContext) m_Context;

    shared_ptr<OCCDocument> m_OCCDoc;
signals:

};

#endif // OCCVIEW_H
