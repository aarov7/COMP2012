class test{
public:
    void virtual inline func() const;
};
class testDer: public test{
public:
    virtual void inline func() const override final;
};