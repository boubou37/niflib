/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiExtraData::TYPE("NiExtraData", &NiObject::TYPE );

NiExtraData::NiExtraData() : nextExtraData(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiExtraData::~NiExtraData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiExtraData::GetType() const {
	return TYPE;
}

NiObject * NiExtraData::Create() {
	return new NiExtraData;
}

void NiExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	if ( info.version >= 0x0A000100 ) {
		NifStream( name, in, info );
	};
	if ( info.version <= 0x04020200 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	if ( info.version >= 0x0A000100 ) {
		NifStream( name, out, info );
	};
	if ( info.version <= 0x04020200 ) {
		if ( nextExtraData != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(nextExtraData) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiExtraData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Name:  " << name << endl;
	out << "  Next Extra Data:  " << nextExtraData << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x04020200 ) {
		nextExtraData = FixLink<NiExtraData>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiExtraData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( nextExtraData != NULL )
		refs.push_back(StaticCast<NiObject>(nextExtraData));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

string NiExtraData::GetName() {
	return name;
}

void NiExtraData::SetName( const string & new_name ) {
	name = new_name;
}

/*! Used to format a human readable string that includes the type of the object */
string NiExtraData::GetIDString() const {
	stringstream out;
	out << NiObject::GetIDString() << " {" << name << "}";
	return out.str();
}

NiExtraDataRef NiExtraData::GetNextExtraData() const {
	return nextExtraData;
}

void NiExtraData::SetNextExtraData( NiExtraData * obj ) {
	nextExtraData = obj;
}

//--END CUSTOM CODE--//
