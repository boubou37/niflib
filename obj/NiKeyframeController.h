/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIKEYFRAMECONTROLLER_H_
#define _NIKEYFRAMECONTROLLER_H_

#include "NiTimeController.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiKeyframeData;

#include "../gen/obj_defines.h"

class NiKeyframeController;
typedef Ref<NiKeyframeController> NiKeyframeControllerRef;

/*!
 * NiKeyframeController - A time controller block for animation key
 * frames.
 */

class NIFLIB_API NiKeyframeController : public NI_KEYFRAME_CONTROLLER_PARENT {
public:
	NiKeyframeController();
	~NiKeyframeController();
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
	NI_KEYFRAME_CONTROLLER_MEMBERS
};

#endif
