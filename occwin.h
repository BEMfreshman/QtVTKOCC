//
// Created by wenluyang on 2022/11/18.
//

#ifndef QTVTKOCC_OCCWIN_H
#define QTVTKOCC_OCCWIN_H

#include <Aspect_Window.hxx>
#include <QWidget>
#include <Standard_WarningsRestore.hxx>
#include <Standard_WarningsDisable.hxx>

class OCCWin: public Aspect_Window
{
public:
    OCCWin(QWidget* wid,const Quantity_NameOfColor thecolor = Quantity_NOC_MATRAGRAY);
    ~OCCWin();

    //! Returns native Window handle
    Aspect_Drawable NativeHandle() const override;

    //! Returns parent of native Window handle.
     Aspect_Drawable NativeParentHandle() const override;

    //! Applies the resizing to the window <me>
     Aspect_TypeOfResize DoResize() override;

    //! Returns True if the window <me> is opened
    //! and False if the window is closed.
     Standard_Boolean IsMapped() const override;

    //! Apply the mapping change to the window <me>
    //! and returns TRUE if the window is mapped at screen.
     Standard_Boolean DoMapping() const override { return Standard_True; }

    //! Opens the window <me>.
     void Map() const override;

    //! Closes the window <me>.
     void Unmap() const override;

     void Position( Standard_Integer& theX1, Standard_Integer& theY1,
                           Standard_Integer& theX2, Standard_Integer& theY2 ) const override;

    //! Returns The Window RATIO equal to the physical
    //! WIDTH/HEIGHT dimensions.
     Standard_Real Ratio() const override;

     void Size( Standard_Integer& theWidth, Standard_Integer& theHeight ) const override;

     Aspect_FBConfig NativeFBConfig() const Standard_OVERRIDE { return NULL; }

    DEFINE_STANDARD_RTTIEXT(OCCWin,Aspect_Window)

protected:
    QWidget* myWidget;

    Standard_Integer myXLeft;
    Standard_Integer myYTop;
    Standard_Integer myXRight;
    Standard_Integer myYBottom;
};


#endif //QTVTKOCC_OCCWIN_H
