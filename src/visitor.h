/**
 *  \file visitor.h
 *  Class Visitor
 *
 **/
#ifndef CSYMPY_VISITOR_H
#define CSYMPY_VISITOR_H

#include "basic.h"

namespace CSymPy {

class Visitor {
public:
    // It should be possible to simplify this using the approach described at:
    // http://stackoverflow.com/a/11802080/479532
    // http://stackoverflow.com/a/7877397/479532
    virtual void visit(const Symbol &) = 0;
    virtual void visit(const Add &) = 0;
    virtual void visit(const Mul &) = 0;
    virtual void visit(const Pow &) = 0;
    virtual void visit(const Number &) = 0;
    virtual void visit(const Function &) = 0;
    virtual void visit(const Log &) = 0;
    virtual void visit(const Derivative &) = 0;
};

class HasVisitor : public Visitor {
private:
    RCP<const Symbol> x_;
    bool has_;
public:
    // TODO: allow to return true/false from the visit() methods, and if it
    // returns false, stop the traversal in pre/postorder_traversal().
    virtual void visit(const Symbol &x) {
        if (x_->__eq__(x)) has_ = true;
    }
    virtual void visit(const Add &) {
    }
    virtual void visit(const Mul &) {
    }
    virtual void visit(const Pow &) {
    }
    virtual void visit(const Number &) {
    }
    virtual void visit(const Function &) {
    }
    virtual void visit(const Log &) {
    }
    virtual void visit(const Derivative &) {
    }
    bool apply(const Basic &b, const RCP<const Symbol> &x) {
        x_ = x;
        has_ = false;
        b.preorder_traversal(*this);
        return has_;
    }
};

bool has_symbol(const Basic &b, const RCP<const Symbol> &x);

} // CSymPy

#endif
