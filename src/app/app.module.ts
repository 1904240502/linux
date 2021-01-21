import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
// import { MatIconModule } from "@angular/material/icon";
import { AppComponent } from './app.component';
import { MainComponent } from './main/main.component';
import { TitlebarComponent } from './titlebar/titlebar.component';
import { MatToolbarModule } from '@angular/material/toolbar';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { FacialComponent } from './facial/facial.component';
import { MassageTherapyComponent } from './massage-therapy/massage-therapy.component';
import { SpecialtyTreatmentsComponent } from './specialty-treatments/specialty-treatments.component';
import { EspapePackagesComponent } from './espape-packages/espape-packages.component';
import { SpecialsGiftcardsComponent } from './specials-giftcards/specials-giftcards.component';
import { FooterComponent } from './footer/footer.component';
import { FootReflexologyComponent } from './foot-reflexology/foot-reflexology.component';
import { ToolbarComponent } from './toolbar/toolbar.component';
import { RouterModule } from '@angular/router';


@NgModule({
  declarations: [
    AppComponent,
    MainComponent,
    TitlebarComponent,
    FacialComponent,
    MassageTherapyComponent,
    SpecialtyTreatmentsComponent,
    EspapePackagesComponent,
    SpecialsGiftcardsComponent,
    FooterComponent,
    FootReflexologyComponent,
    ToolbarComponent,
  ],
  imports: [
    BrowserModule,
    MatToolbarModule,
    BrowserAnimationsModule,
    RouterModule.forRoot([
      { path: 'home', component: MainComponent },
      { path: 'app-facial', component: FacialComponent },
      { path: 'app-massage-therapy', component: MassageTherapyComponent },
      { path: 'app-specialty-treatments', component: SpecialtyTreatmentsComponent },
      { path: 'app-espape-packages', component: EspapePackagesComponent },
      { path: 'app-specials-giftcards', component: SpecialsGiftcardsComponent },
      { path: 'app-foot-reflexology', component: FootReflexologyComponent },
      { path: '', redirectTo: '/home', pathMatch: 'full' },
    ]),
    // MatIconModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
