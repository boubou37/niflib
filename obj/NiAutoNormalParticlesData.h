/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIAUTONORMALPARTICLESDATA_H_
#define _NIAUTONORMALPARTICLESDATA_H_

#include "NiTriBasedGeomData.h"

#include "../gen/obj_defines.h"

class NiAutoNormalParticlesData;
typedef Ref<NiAutoNormalParticlesData> NiAutoNormalParticlesDataRef;

/*!
 * NiAutoNormalParticlesData - Particle system data block (with automatic
 * normals?).
 */

class NIFLIB_API NiAutoNormalParticlesData : public NI_AUTO_NORMAL_PARTICLES_DATA_PARENT {
public:
	NiAutoNormalParticlesData();
	~NiAutoNormalParticlesData();
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
	NI_AUTO_NORMAL_PARTICLES_DATA_MEMBERS
};

#endif
