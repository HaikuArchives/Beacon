/*
 * Copyright 2009 Haiku, Inc.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Ankur Sethi (get.me.ankur@gmail.com)
 */

#ifndef _FEEDER_H_
#define _FEEDER_H_

#include <Looper.h>
#include <Message.h>
#include <Query.h>
#include <VolumeRoster.h>


class Feeder : public BLooper {
	public :
		Feeder() ;

		// BLooper methods
		virtual void MessageReceived(BMessage *message) ;
		virtual bool QuitRequested() ;

		// Feeder methods
		void StartWatching() ;
		void SaveSettings(BMessage *settings) ;
		status_t GetNextRef(entry_ref *ref) ;
		BList* GetVolumeList() ;

	private :
		// Feeder methods
		void LoadSettings(BMessage *settings) ;
		void AddQuery(BVolume *volume) ;
		void AddEntry(entry_ref *ref) ;
		void RemoveQuery(BVolume *volume) ;
		void RetrieveStaticRefs(BQuery *query) ;
		void HandleQueryUpdate(BMessage *message) ;
		void HandleDeviceUpdate(BMessage *message) ;
		bool Excluded(entry_ref *ref) ;
		bool IsHidden(entry_ref *ref) ;

		// Data members
		bool			fMonitorRemovableDevices ;
		BVolumeRoster	fVolumeRoster ;
		BList			fQueryList ;
		BList			fEntryList ;
		BList			fExcludeList ;
		BList 			fVolumeList ;
} ;

#endif /* _FEEDER_H_ */