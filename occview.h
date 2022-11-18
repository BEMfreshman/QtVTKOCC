#ifndef OCCVIEW_H
#define OCCVIEW_H

#include <QWidget>
#include <AIS_InteractiveContext.hxx>

class OCCView : public QWidget
{
    Q_OBJECT
public:
    explicit OCCView(QWidget *parent = nullptr);
    virtual ~OCCView() = default;

    [[nodiscard]] const Handle(AIS_InteractiveContext)& getContext() const;

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

signals:

};

#endif // OCCVIEW_H