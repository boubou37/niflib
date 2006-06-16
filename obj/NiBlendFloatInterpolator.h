/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBLENDFLOATINTERPOLATOR_H_
#define _NIBLENDFLOATINTERPOLATOR_H_

#include "NiBlendInterpolator.h"

#include "../gen/obj_defines.h"

class NiBlendFloatInterpolator;
typedef Ref<NiBlendFloatInterpolator> NiBlendFloatInterpolatorRef;

/*!
 * NiBlendFloatInterpolator - An interpolator for a float.
 */

class NIFLIB_API NiBlendFloatInterpolator : public NI_BLEND_FLOAT_INTERPOLATOR_PARENT {
public:
	NiBlendFloatInterpolator();
	~NiBlendFloatInterpolator();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_BLEND_FLOAT_INTERPOLATOR_MEMBERS
};

#endif
