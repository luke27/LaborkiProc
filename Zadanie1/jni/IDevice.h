/**
 * 2011-11-02
 */

#pragma once

namespace PG
{
	/**
	 * Klasa reprezentująca urządzenia, intefejs
	 */
	class IDevice
	{
	public:
		/// inicjalizacja
		virtual void init() = 0;
		/// pętla aplikacji
		virtual void appLoop() = 0;

		virtual ~IDevice()
		{

		}
	};
}
